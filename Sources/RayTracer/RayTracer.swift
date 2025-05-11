import cpplib

@main
struct RayTracer {
  public static func main() async {
    let i = hello()
    try? await Task.sleep(for: .milliseconds(200))
    print("Hello from C++: \(i)")
  }
}
