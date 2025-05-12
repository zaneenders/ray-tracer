# Ray Tracer

A simple ray tracer using the Swift, C++ interop following 
[Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
 .

## Run

The program outputs the image to standard out so we can capture the output into
a file.

```console
swift run > image.ppm
```

Open image.ppm using something that supports the `.ppm` image format.

## Why?

I am learning C++ and wanna leverage my knowledge of Swift to do so. I’m sure I
will run into limitations but thats half the fun of this project.

### Concurrency

Swift has pretty easy concurrency abstraction that I am comfortable and where 
Swift lacks is in low level control and speed over memory. So my thought is do 
high level concurrency in Swift and low level optimizations in C++.

### Testing

I don’t know best practices for testing C++ so figured I would just use Swift’s
`Testing` as once the interop is setup writing test in Swift is pretty easy.