// swift-tools-version: 6.1
import PackageDescription

let package = Package(
  name: "ray-tracer",
  platforms: [
    .macOS(.v15)
  ],
  targets: [
    .target(name: "cpplib"),
    .executableTarget(
      name: "RayTracer",
      dependencies: [
        "cpplib"
      ],
      swiftSettings: [.interoperabilityMode(.Cxx)]),
    .testTarget(
      name: "RayTracerTest",
      dependencies: [
        "RayTracer"
      ],
      swiftSettings: [.interoperabilityMode(.Cxx)]),
  ]
)
