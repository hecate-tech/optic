package main

import rl "github.com/hecate-tech/raylib-go/raylib"

type Game struct {
	Camera rl.Camera
	Color  rl.Color
	Player *Player
}

func NewGame() *Game {
	g := &Game{
		Camera: rl.Camera{
			Position: rl.NewVector3(3.0, 3.0, 3.0),
			Target:   rl.NewVector3(0.0, 1.5, 0.0),
			Up:       rl.NewVector3(0.0, 1.0, 0.0),
			Fovy:     45.0,
		},
		Color:  rl.White,
		Player: NewPlayer(),
	}

	rl.SetCameraMode(g.Camera, rl.CameraOrbital)

	return g
}

func (g *Game) Unload() {
	g.Player.Unload()
}

func (g *Game) Update() {
	rl.UpdateCamera(&g.Camera)

	rl.BeginDrawing()
	rl.ClearBackground(g.Color)

	g.update3D()

	rl.EndDrawing()
}

func (g *Game) update3D() {
	rl.BeginMode3D(g.Camera)

	g.Player.Update()
	rl.DrawGrid(10, 1.0)
	rl.DrawGizmo(g.Player.Position)

	rl.EndMode3D()
}

const (
	_playerTexturePath = "dwarf_diffuse.png"
	_playerModelPath   = "dwarf.obj"
)

type Player struct {
	Model    rl.Model
	Texture  rl.Texture2D
	Position rl.Vector3
	Color    rl.Color
	Scale    float32
}

func NewPlayer() *Player {
	p := &Player{
		Model:    rl.LoadModel(_playerModelPath),
		Texture:  rl.LoadTexture(_playerTexturePath),
		Position: rl.NewVector3(0.0, 0.0, 0.0),
		Scale:    2.0,
		Color:    rl.White,
	}

	p.Model.Material.Maps[rl.MapDiffuse].Texture = p.Texture

	return p
}

func (p *Player) Unload() {
	rl.UnloadTexture(p.Texture)
	rl.UnloadModel(p.Model)
}

func (p *Player) Update() {
	rl.DrawModel(p.Model, p.Position, p.Scale, p.Color)
}
