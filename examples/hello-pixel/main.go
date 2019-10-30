package main

import (
	"image"
	"log"

	"github.com/faiface/pixel"
	"github.com/faiface/pixel/pixelgl"
	gl "github.com/fogleman/fauxgl"
	"github.com/nfnt/resize"
	"golang.org/x/image/colornames"
)

const (
	scale  = 4    // optional supersampling
	width  = 1024 // output width in pixels
	height = 1024 // output height in pixels
	fovy   = 40   // vertical field of view in degrees
	near   = 1    // near clipping plane
	far    = 10   // far clipping plane
)

var (
	windowSize = image.Point{X: 1024, Y: 1024}
	eye        = gl.V(-3, 1, 2)                // camera position
	center     = gl.V(0, 0, 0)                 // view center position
	up         = gl.V(0, 0, 1)                 // up vector
	light      = gl.V(-1, 1, 0.25).Normalize() // light direction
)

func main() {
	pixelgl.Run(run)
}

func run() {
	cfg := pixelgl.WindowConfig{
		Title:  "Hello",
		Bounds: pixel.R(0, 0, 1024, 768),
	}

	win, err := pixelgl.NewWindow(cfg)
	if err != nil {
		panic(err)
	}

	var (
		img    image.Image
		pdata  *pixel.PictureData
		sprite *pixel.Sprite
	)

	var count int
	for !win.Closed() {
		log.Printf("render[%d]\n", count)
		count++
		img = resize.Resize(width, height, renderImage(), resize.Bilinear)

		pdata = pixel.PictureDataFromImage(img)
		sprite = pixel.NewSprite(pdata, pdata.Bounds())

		win.Clear(colornames.Slategrey)

		sprite.Draw(win, pixel.IM.Moved(
			win.Bounds().Center(),
		))

		win.Update()
	}
}

func renderImage() image.Image {
	// load the mesh
	mesh, err := gl.LoadOBJ("capsule.obj")
	if err != nil {
		panic(err)
	}

	// load the texture
	texture, err := gl.LoadTexture("capsule.jpg")
	if err != nil {
		panic(err)
	}

	// fit mesh in a bi-unit cube centered at the origin
	mesh.BiUnitCube()

	// create a rendering context
	context := gl.NewContext(width*scale, height*scale)

	// create transformation matrix and light direction
	aspect := float64(width) / float64(height)
	matrix := gl.LookAt(eye, center, up).Perspective(fovy, aspect, near, far)

	// render
	shader := gl.NewPhongShader(matrix, light, eye)
	shader.Texture = texture
	context.Shader = shader
	context.DrawMesh(mesh)

	// downsample image for antialiasing
	return context.Image()
	// img := context.Image()
	// img = resize.Resize(width, height, img, resize.Bilinear)
}
