open Jest;

describe("Expect", () => {
  open Expect;

  test("1 + 2 should equal 3", () =>
    expect(1 + 2) |> toBe(3))
});
