console.time('time');
fetch("input.txt")
.then(res => res.text())
.then(r => {
    const result = r.split('\r\n');
    let highest = {c: 0, i: 0};
    let count = 0;
    for (let i in result) {
        if (result[i] > 0) {
            count += parseInt(result[i]);
        } else {
            if (count > highest.c) {
                highest = {c: count, i: i};
            }
            count = 0;
        }
    }
    console.log(highest);
}
);
console.timeEnd('time');