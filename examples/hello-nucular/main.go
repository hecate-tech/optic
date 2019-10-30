package main

import (
	"image"
	"log"
	"sync"

	// "github.com/aarzilli/nucular"
	"github.com/aarzilli/nucular"
	gl "github.com/fogleman/fauxgl"
	"github.com/nfnt/resize"
)

var count int

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
	// wnd := nucular.NewMasterWindow(0, "Hello", updaefn)
	wnd := nucular.NewMasterWindowSize(0, "Hello", image.Point{800, 600}, updatefn)

	// wnd.SetStyle(style.FromTheme(style.DarkTheme, 2.0))
	// wnd.Lock()

	wnd.Main()
}

func render(w *nucular.Window) {
	for {
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
		img := context.Image()
		img = resize.Resize(width, height, img, resize.Bilinear)

		if rgba, ok := img.(*image.RGBA); ok {
			w.Image(rgba)
		} else {
			log.Fatalf("failed to convert image to rgba")
		}

	}
}

var (
	mrender = &sync.Once{}
)

func updatefn(w *nucular.Window) {
	// w.RowScaled(1024).StaticScaled(1024)
	w.Row(1024).Static(1024)

	mrender.Do(func() {
		go render(w)
	})
}
