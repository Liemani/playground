/**
 * Generates a normally distributed random number with mean 0 and standard deviation 1.
 * Uses the Box-Muller transform.
 */
function gaussianRandom(min, max, skew) {
  let u;
  let v;
  let z;

  while (true) {
    // Convert [0, 1) to (0, 1) to avoid taking log(0)
    u = 0;
    while (u === 0) u = Math.random();

    v = 0;
    while (v === 0) v = Math.random();

    z = Math.sqrt(-2.0 * Math.log(u)) * Math.cos(2.0 * Math.PI * v);
    z = z / 10.0 + 0.5;

    if (0 <= z && z <= 1)
      break;
  }

  z = Math.pow(z, skew);
  z *= max - min;
  z += min;

  return z;
}

// Example usage:
const samples = [];
for (let i = 0; i < 10; i++) {
  randomNumberString = gaussianRandom(50, 100, 1).toFixed(2);
  samples.push(randomNumberString);
}

console.log("Gaussian samples:", samples);
