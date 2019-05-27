type route =
  | Login
  | Home
  | Historic;

type changeRoute =
  | ChangeRoute(route);

let getTitle =
  fun
  | Home => "Home"
  | Login => "Home"
  | Historic => "Historic";