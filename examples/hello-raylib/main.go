package main

import rl "github.com/hecate-tech/raylib-go/raylib"

func main() {
	rl.InitWindow(int32(450), int32(800), "raylib [models] example - obj model loading")

	camera := rl.Camera{}
	camera.Position = rl.NewVector3(3.0, 3.0, 3.0)
	camera.Target = rl.NewVector3(0.0, 1.5, 0.0)
	camera.Up = rl.NewVector3(0.0, 1.0, 0.0)
	camera.Fovy = 45.0

	dwarf := rl.LoadModel("dwarf.obj")             // Load OBJ model
	texture := rl.LoadTexture("dwarf_diffuse.png") // Load model texture

	dwarf.Material.Maps[rl.MapDiffuse].Texture = texture // Set dwarf model diffuse texture

	position := rl.NewVector3(0.0, 0.0, 0.0) // Set model position

	rl.SetTargetFPS(60)
	rl.SetCameraMode(camera, rl.CameraOrbital)

	for !rl.WindowShouldClose() {
		rl.UpdateCamera(&camera)

		rl.BeginDrawing()

		rl.ClearBackground(rl.DarkGray)

		rl.BeginMode3D(camera)

		rl.DrawModel(dwarf, position, 2.0, rl.White) // Draw 3d model with texture
		rl.DrawGrid(10, 1.0)                         // Draw a grid
		rl.DrawGizmo(position)                       // Draw gizmo

		rl.EndMode3D()

		rl.EndDrawing()
	}

	rl.UnloadTexture(texture) // Unload texture
	rl.UnloadModel(dwarf)     // Unload model

	rl.CloseWindow()
}
