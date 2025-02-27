function toLocalISOString(dateString) {
  const date = new Date(dateString); // Parse the date string
  const timezoneOffset = -date.getTimezoneOffset(); // Offset in minutes
  console.log("timezoneOffset : " + timezoneOffset);
  const sign = timezoneOffset >= 0 ? "+" : "-"; // Determine the sign
  const hours = String(Math.floor(Math.abs(timezoneOffset) / 60)).padStart(2, '0'); // Hours part
  const minutes = String(Math.abs(timezoneOffset) % 60).padStart(2, '0'); // Minutes part

  console.log("dateString : " + dateString);
  console.log("date : " + date);
  console.log("date.toISOString() : " + date.toISOString());
  const localDateString = date.toISOString().replace("Z", `${sign}${hours}:${minutes}`);
  return localDateString;
}

// Example Usage
const result = toLocalISOString("2025-01-14T10:00:00");
console.log(result); // Output: 2025-01-14T10:00:00+09:00 (if the local timezone is UTC+09:00)
