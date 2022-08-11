https://www.hackerrank.com/challenges/truck-tour/problem

'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputString = inputString.split('\n');

  main();
});

function readLine() {
  return inputString[currentLine++];
}

/*
 * Complete the 'truckTour' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY petrolpumps as parameter.
 */

function truckTour(petrolpumps) {
  let current_pump = 0;
  const total_pumps = petrolpumps.length;
  while (current_pump < total_pumps) {
    let out_of_gas = false;
    let tank = 0;
    for (let i = current_pump; i < total_pumps + current_pump; i++) {
      const [p, d] = petrolpumps[i];
      tank += p;
      if (d > tank) {
        out_of_gas = true;
        break;
      } else {
        tank -= d;
      }
    }
    if (!out_of_gas) return current_pump;
    //const temp = petrolpumps.shift();
    petrolpumps.push(petrolpumps[current_pump]);
    current_pump++;
  }
  return current_pump;
}

function main() {
  const ws = fs.createWriteStream('salida.txt');

  const n = parseInt(readLine().trim(), 10);

  let petrolpumps = Array(n);

  for (let i = 0; i < n; i++) {
    petrolpumps[i] = readLine().replace(/\s+$/g, '').split(' ').map(petrolpumpsTemp => parseInt(petrolpumpsTemp, 10));
  }

  const result = truckTour(petrolpumps);

  ws.write(result + '\n');

  ws.end();
}


//console.log(truckTour([[1, 5], [10, 3], [3, 4]])); // 1