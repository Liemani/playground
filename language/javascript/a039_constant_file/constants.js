// constants.js
var CONSTANTS = {
  API_URL: "https://api.example.com",
  TIMEOUT: 5000,
  MAX_RETRIES: 3
};

// Export for use in other files
if (typeof module !== 'undefined' && module.exports) {
  module.exports = CONSTANTS;
}
