type state = {
    currentIndex: int,
};
type action = SetDifficulty(CardType.difficulty);

let reducer = (state, action) =>
switch (action) {
    | SetDifficulty(_) => { currentIndex: state.currentIndex + 1 }
    };

let initialState = {
    currentIndex: 0
};

[@react.component]
let make = (~cards: list(CardType.card)) => {
    let (state, dispatch) = React.useReducer(reducer, initialState);
    let toCard = (card: CardType.card) => {
        <Card question={card.question} answer={card.answer} setDifficulty={(difficulty) => dispatch(SetDifficulty(difficulty))}/>;
    };
    let cardsElements =
        List.nth(cards, state.currentIndex)
            |> toCard;
    <div>
    { cardsElements }
    </div>
}
