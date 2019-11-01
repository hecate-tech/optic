package main

import rl "github.com/hecate-tech/raylib-go/raylib"

func main() {
	rl.InitWindow(
		int32(800), int32(450), "Hello Go",
	)

	rl.SetTargetFPS(60)

	game := NewGame()

	for !rl.WindowShouldClose() {
		game.Update()
	}

	game.Unload()

	rl.CloseWindow()
}
