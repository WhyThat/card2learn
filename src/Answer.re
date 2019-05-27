[@react.component]
let make = (~text, ~isShown, ~validateAnswer) =>
  isShown ?
    <div>
      {ReasonReact.string(text)}
      <div>
        <button onClick={_event => validateAnswer(CardType.Easy)}>
          {ReasonReact.string("Easy")}
        </button>
        <button onClick={_event => validateAnswer(CardType.Medium)}>
          {ReasonReact.string("Medium")}
        </button>
        <button onClick={_event => validateAnswer(CardType.Hard)}>
          {ReasonReact.string("Hard")}
        </button>
      </div>
    </div> :
    ReasonReact.string("");