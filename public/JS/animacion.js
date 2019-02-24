import anime from './anime.es.js';

var AnimacionTermo = anime({
  targets: '#termo',
  keyframes: [
    {translateY: 60}
  ],
  duration: 2000,
  easing: 'easeOutElastic(4, .5)',

});