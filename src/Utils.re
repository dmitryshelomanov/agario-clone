let unwrap = (value: option('a)) => {
  switch (value) {
  | Some(v) => v
  | None => failwith("unwrap panic")
  };
};
