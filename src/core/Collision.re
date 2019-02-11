type sideOfBoundaries =
  | Left(float)
  | Right(float);

let outOfBoundaries = (side, p) =>
  switch (side) {
  | Left(p1) => p < p1
  | Right(p1) => p > p1
  };
