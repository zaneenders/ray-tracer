import Testing

@testable import RayTracer
@testable import cpplib

@Suite("Ray Tracer Test")
struct RayTracerTest {
  @Test func testName() async throws {
    let i = hello()
    #expect(i == 69)
  }
}
