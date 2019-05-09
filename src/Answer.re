[@react.component]
let make = (~text, ~isShown, ~dispatch) => {
  isShown ?
	<div>
    {ReasonReact.string(text)}
    <div>
      <button onClick={_event => dispatch(CardType.Easy)}>
        {ReasonReact.string("Easy")}
      </button>
      <button onClick={_event => dispatch(CardType.Medium)}>
        {ReasonReact.string("Medium")}
      </button>
      <button onClick={_event => dispatch(CardType.Hard)}>
        {ReasonReact.string("Hard")}
      </button>
    </div>
  </div> : ReasonReact.string("");
};
