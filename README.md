<h1 align="center">miniRT</h1>


<i><p  align="center" font-type="italic"> A simple Ray Tracer </p></i>


## About

This project is a recriation of miniRT from 42 school as an exercise to help me to fix some concepts of raytracing. The [original project](https://github.com/librity/ft_minirt) was made with [lpaulo-m](https://github.com/librity), but I decided to implement it from scratch using my own [libft](https://github.com/pedro-pn/libft_complete) and going further in The Ray Tracing Challange book chapters.

## Description

This project is a Ray Tracer coded in C using [minilibx](https://github.com/42Paris/minilibx-linux) library.


## The project

### Input scene

miniRT can create images based on simple geometric forms like spheres, planes, cylinders, cubes, cones and triangles. These forms can be configured in a scene file with .rt extension.

#### View elements

A scenario can be built starting with three view elements:

 - Camera
 - Ambient Light
 - Light

The `camera` is "the eye" of the scene and it is represented with the `C` letter in the configuration file. Them it is followed by its origin position, a normalized vector to the direction where it points and its field of view (in degrees).

```C	0,0,0	0,0,1	70```

The `Ambient Light` is the background light for the whole scene and it is represented with the letter "A". Then it is followed by its brightness (0 to 1) and its RGB color.

```A  0.7   255,255,255```

The `light` is a point light in the scene from where all objects are iluminated. The light is represented by and `L`, followed by its position and its brightness.

```L	0,10,-10	1.0```


#### Objects

#### Sphere

A sphere is represented by the `sp` token, followed by its position, diameter and RGB color.

```sp	0,0,0	2	255,0,0```

#### Plane

A plane is represented by the `pl` token, followed by its position, normal vector (it must be normalized) and RGB color.

```pl	0,0,0	0,-3,0	125,125,125```

#### Cylinder

A cylinder is represented by the `cy` token, followed by its position, normal vector (it must be normalized), diameter, height and RGB color.

```cy    -5,0,0            0,1,0    3    2    255,255,0```

#### Cones

A cone is represented by the `cn` token, followed by followed by its position, normal vector (it must be normalized), diameter, height and RGB color.

```cn    5,0,0            0,1,0    3    2    255,0,255```

### Cubes

A cube is represented by the `cb` token, followed by its position, diameter, height, depth and RGB color.

```cb	  0,1,0			-0.70710,0,-0.70710   2 2 3 		255,0,255```

---

## Usage


### Requirements

miniRT requires clang-12 compiler, standard C compiler and [minilibx](https://github.com/42Paris/minilibx-linux) installed. 

### Implemented:

- [x] Spheres;
- [x] Planes;
- [x] Cubes;
- [x] Phong reflection model;
- [x] Shadows;
- [x] Patterns;
- [x] Reflection;
- [x] Refraction;
- [x] Multi-thread renderization;
- [X] Cylinders;
- [X] Cones;
- [X] Groups;
- [X] Bounding boxes optmization;
- [X] Bounding Volume Hierarchies (BVH);
- [X] Triangles;
- [X] Wavefront OBJ file parser;
- [X] Smooth Triangles;
- [X] Parser scene;

### To implement:

- [ ] Cones in scene;
- [ ] Groups in scene;
- [ ] Triangles in scene;
- [ ] Patterns in scene;
- [ ] Wavefront in scene;
- [ ] Multiple lights;
- [ ] CSG;
- [ ] Focal Blur;
- [ ] Soft shadows;
- [ ] Anti-aliasing;
- [ ] Texture maps;

### Rendered images

<img src="./rendered-scenes/pink_sphere.png" alt="pink_sphere"/>

<img src="./rendered-scenes/book_cover.png" alt="The Ray Tracer Challange - Book Cover"/>


#