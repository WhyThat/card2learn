type route = Router.route;

type state = {route};

type action =
  | ChangeRoute(route);

let reducer = (action, _state) =>
  switch (action) {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch (url.path) {
  | ["login"] => Router.Login
  | _ => Router.Home
  };

let currentRoute = ReasonReact.Router.dangerouslyGetInitialUrl();

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  switch (mapUrlToRoute(url)) {
  | Login => React.string("login")
  | _ => React.string("other")
  };
};