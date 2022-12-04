console.time('time');
fetch("input.txt")
.then(res => res.text())
.then(r => {
    const result = r.split('\r\n');
    let highest = {c: 0, i: 0};
    let second = {c: 0, i:0};
    let third = {c: 0, i:0};
    let count = 0;
    for (let i in result) {
        if (result[i] > 0) {
            count += parseInt(result[i]);
        } else {
            if (count > highest.c) {
                third = second;
                second = highest;
                highest = {c: count, i: i};
            } else if (count > second.c) {
                third = second;
                second = {c: count, i: i};
            } else if (count > third.c) {
                third = {c: count, i: i};
            }
            count = 0;
        }
    }
    console.log(highest.c + second.c + third.c);
    document.body.innerHTML = `Result: ${highest.c + second.c + third.c}`;
}
);
console.timeEnd('time');