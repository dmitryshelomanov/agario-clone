type t = {
  x: float,
  y: float,
};

let vector2 = (x, y) => {x, y};
let plus = (v, v1) => vector2(v.x +. v1.x, v.y +. v1.y);
let multiply = (v, n) => vector2(v.x *. n, v.y *. n);
let negative = v => multiply(v, -1.0);
let minus = (v, v1) => plus(v, negative(v1));
let division = (v, n) => multiply(v, 1.0 /. n);
// vector's magnitude
let abs = v => sqrt(v.x ** 2.0 +. v.y ** 2.0);
let distance = (v, v1) => abs(minus(v1, v));
let norm = v => {
  let magnitude = abs(v);
  magnitude == 0.0 ? v : division(v, magnitude);
};