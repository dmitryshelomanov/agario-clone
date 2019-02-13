type t = {
  x: float,
  y: float,
};

let vector2 = (x, y) => {x, y};
let (+) = (v, v1) => vector2(v.x +. v1.x, v.y +. v1.y);
let (*) = (v, n) => vector2(v.x *. n, v.y *. n);
let (!) = (v) => v * (-1.0);
let (-) = (v, v1) => v + (!v1);
let (/) = (v, n) => v * (1.0 /. n);
// vector's magnitude
let abs = (v) => sqrt(v.x ** 2.0 +. v.y ** 2.0);
let distance = (v, v1) => abs(v1 - v);
let norm = (v) => {
  let magnitude = abs(v);
  magnitude == 0.0 ? v : v / magnitude;
};
