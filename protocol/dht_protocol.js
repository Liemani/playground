class Protocol {
  // format : message'\n'
  //  message : {"temperature":value,"humidity":value}
  //    value : number
  //  message is json

  static indexIsNotFound = -1;
  static messageDelimiter = '\n';
  static regExpPattern = "^{\"temperature\":[^,]*,\"humidity\":[^}]*}$";

  static isReadAMessage(buffer) {
    const delimiter = this.messageDelimiter;
    const indexOfDelimiter = buffer.indexOf(delimiter);

    return indexOfDelimiter != this.messageDelimiter;
  }

  static getAMessageFrom(buffer) {
    const delimiter = this.messageDelimiter;
    const indexOfDelimiter = buffer.indexOf(delimiter);
    const message = buffer.slice(0, indexOfDelimiter);

    return message;
  }

  static removeAMessageFrom(buffer) {
    const delimiter = this.messageDelimiter;
    const indexOfDelimiter = buffer.indexOf(delimiter);
    const bufferRemovedAMessage = buffer.slice(indexOfDelimiter + 1);

    return bufferRemovedAMessage;
  }

  static isValid(message) {
    const regexp = new RegExp(this.regExpPattern);

    return regexp.test(message);
  }

  static objectFrom(message) {
    return JSON.parse(message)
  }

}

module.exports = Protocol;
