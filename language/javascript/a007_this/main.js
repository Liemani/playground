function EventEmitter() {
  console.log('[function start] EventEmitter()');
  EventEmitter.init.call(this);
  console.log('[function end] EventEmitter()');
}

EventEmitter.prototype.once = function once(type, listener) {
  checkListener(listener);
  this.on(type, _onceWrap(this, type, listener));
  return this;
};

console.log('[start]');
EventEmitter();
console.log('[end]');
