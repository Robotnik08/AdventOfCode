console.time('time');
fetch("input.txt")
.then(res => res.text())
.then(r => {
    const result = r.split('\r\n');
    let score = 0;
    for (let i in result) {
        score += eval(result[i]);
    }
    console.log(score);
}
);
console.timeEnd('time');

function eval (game) {
    let opp = game.charAt(0);
    let you = game.charAt(2);
    switch(opp) {
        case"A":
            if (you == "X") return 3;
            if (you == "Y") return 4;
            if (you == "Z") return 8;
            break;
        case"B":
            if (you == "X") return 1;
            if (you == "Y") return 5;
            if (you == "Z") return 9;
            break;
        case"C":
            if (you == "X") return 2;
            if (you == "Y") return 6;
            if (you == "Z") return 7;
            break;
    }
    console.error('not found');
    return 0;
}