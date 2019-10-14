let map = f =>
  fun
  | Some(v) => Some(f(v))
  | None => None;

let andThen = (f: 'a => option('b)) =>
  fun
  | Some(v) => f(v)
  | None => None;

let unwrapOr = default =>
  fun
  | Some(v) => v
  | None => default;