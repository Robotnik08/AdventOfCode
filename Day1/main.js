async function fetchInput () {
    const r = await fetch("input.txt");
    console.log(r.text());
}
fetchInput();