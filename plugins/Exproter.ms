rollout Exporter "Exporter" width: 128 height: 34 (
	button exportBtn "Export" pos: [8, 8] width: 48 height: 18 enabled: true
	button importBtn "Import" pos: [64, 8] width: 48 height: 18 enabled: true
	on exportBtn pressed do (
		dir = getSavePath()
		for obj in selection do (
			filename = dir + "\\" + obj.name + ".dat"
			file = fopen filename "wb"
			
			pos = obj.position
			m = snapshotAsMesh obj
			if (m.numTVerts == 0) then (
				setNumTVerts m 1
				buildTVFaces m
			)

			WriteLong file m.numVerts
			for i = 1 to m.numVerts do (
				vert = getVert m i
				vert -= pos
				
				WriteFloat file vert.x
				WriteFloat file vert.y
				WriteFloat file vert.z
			)

			WriteLong file m.numTVerts
			for i = 1 to m.numTVerts do (
				vert = getTVert m i
				
				WriteFloat file vert.x
				WriteFloat file vert.y
				WriteFloat file vert.z
			)

			WriteLong file m.numFaces
			for i = 1 to m.numFaces do (
				face = getFace m i
				tface = getTVFace m i
				mat = getFaceMatID m i
				part = getFaceSmoothGroup m i
				
				WriteLong file mat
				WriteLong file part
				WriteLong file face[1]
				WriteLong file face[2]
				WriteLong file face[3]
				WriteLong file tface[1]
				WriteLong file tface[2]
				WriteLong file tface[3]
			)
			fclose file
		)
	)
	on importBtn pressed do (
		filename = getOpenFileName types:"Model(*.dat)|*.dat|"
		file = fopen filename "rb"

		vertArray = #()
		tvertArray = #()
		faceArray = #()
		tfaceArray = #()
		matidArray = #()
		sgroupArray = #()

		numVerts = ReadLong file #unsigned

		for i = 1 to numVerts do (
			x = ReadFloat file
			y = ReadFloat file
			z = ReadFloat file
			vert = Point3 x y z
			append vertArray vert
		)

		numTVerts = ReadLong file #unsigned

		for i = 1 to numTVerts do (
			tx = ReadFloat file
			ty = ReadFloat file
			tz = ReadFloat file
			tvert = Point3 tx ty tz
			append tvertArray tvert
		)

		numFaces = ReadLong file #unsigned

		for i = 1 to numFaces do (
			matid = ReadLong file #unsigned
			sgroup = ReadLong file #unsigned
			
			x = ReadLong file #unsigned
			y = ReadLong file #unsigned
			z = ReadLong file #unsigned
			face = Point3 x y z

			tx = ReadLong file #unsigned
			ty = ReadLong file #unsigned
			tz = ReadLong file #unsigned
			tface = Point3 tx ty tz
			
			append matidArray matid
			append sgroupArray sgroup
			append faceArray face
			append tfaceArray tface
		)

		fclose file

		m = mesh vertices: vertArray faces: faceArray tvertices: vertArray tfaces: faceArray
		for i = 1 to numFaces do (
			setFaceSmoothGroup m i sgroupArray[i]
			setFaceMatID m i matidArray[i]
		)
		update m
		m.name = getFilenameFile filename
	)
)

createDialog Exporter
cui.registerDialogBar Exporter style: #(#cui_dock_top, #cui_floatable)
cui.DockDialogBar Exporter #cui_dock_top