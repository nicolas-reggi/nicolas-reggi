# Estructuras Dinámicas

<h3><b>Diseño de prototipos:</b></h3>


En esta etapa, desarrollé los diseños preliminares de dos prototipos principales, tomando como base los hallazgos de las fases de experimentación anteriores. 

Fue necesario utilizar herramientas de diseño digital para modelar geometrías precisas y prever su comportamiento estructural en función de los materiales seleccionados.


Durante la planificación, consideré técnicas como corte láser, router CNC, impresión 3D y sellado térmico para su futura fabricación. 

La integración de estos métodos en el proceso de diseño permitió evaluar la viabilidad técnica de los prototipos y asegurar que las propuestas fueran factibles y funcionales.


Este proceso fue muy importante para definir el rumbo teniendo en cuentas los  experimentos iniciales.

 <h3><b>Prototipo 1: Superficies Inflables Geométricas</b></h3>


El primer prototipo combina principios geométricos, materiales rígidos sobre material flexible para desarrollar una superficie inflable dinámica. 

Esta estructura modular, controlada electrónicamente, busca explorar cómo el aire puede transformar formas tridimensionales mientras crea un efecto visual atractivo.


El diseño está compuesto por dos octógonos de PVC flexible soldados en su perímetro, que contienen en su interior triángulos rígidos de acrílico.

 Al inflarse, la interacción entre estos elementos genera una estructura tridimensional dinámica, limitando el movimiento de las superficies a patrones geométricos predefinidos.



Para controlar el inflado y los cambios de forma, se utilizó un sistema basado en una placa ESP32 programada con Arduino, que opera en conjunto con un mini compresor de aire y una válvula solenoide para liberar el aire. 

Este sistema permite ajustar el flujo de aire de manera precisa, ofreciendo una gestión eficiente del movimiento. Además, se integraron LEDs que añaden un componente visual que enriquece el diseño y aspecto estético.


Este prototipo combina diseño, tecnología y materiales de forma distinta, logrando una solución funcional que me resulta muy  interesante. 

El proceso fue un reto significativo que me  permitió explorar nuevas posibilidades que podrán ser utilizadas en  instalaciones interactivas y propuestas arquitectónicas originales.

 <h3><b>Fabricación:</b></h3>

Procesos utilizados:


Corte láser: Para la fabricación de los triángulos de acrílico.


Impresión 3D: patas o soportes para los prototipos y soportes para componentes.


Router CNC: fresado de base de aluminio y tapas.


Soldadura térmica: Técnica para sellar el PVC flexible utilizando una prensa de sublimación.


Software Utilizado:


Diseño 2D y 3D: Autodesk Fusion 360 para el modelado 


Programacion: Arduino IDE


 <h3><b>Lista de materiales:</b></h3>



![](../images/proyecto_f/materiales1.jpg)



<h3><b>Prototipo 2: Estructuras Origami Extensibles</b></h3>
 
El segundo prototipo explora las posibilidades de estructuras extensibles basadas en patrones de origami , integrando geometrías plegables lineales, superficies flexibles, movimientos mecánicos y control electrónico. 


Este diseño combina la estética del origami con un sistema dinámico y controlado, creando una estructura adaptable que aporta movimiento y precisión.


La estructura está compuesta por polígonos de acrílico diseñadas según principios de origami, adheridas a una superficie flexible de PVC.


 Estas formas, al desplegarse, generan un movimiento dinámico y predecible, que amplifica la tridimensionalidad y la interacción con el espacio.


El movimiento lineal es controlado mediante un motor DC con reducción de engranajes, conectado a un tornillo vertical, lo que permite un desplazamiento preciso y suave. 


Este sistema es gestionado por una placa ESP32 programada en lenguaje Arduino, que coordina los movimientos mecánicos en diferentes grados.


Se integraron LEDs  que resaltan los pliegues y formas de la estructura, acentuando la transformación geométrica durante su movimiento.


Este prototipo representa un logro personal significativo, ya que inicialmente no imaginaba que podría funcionar tan bien. 


Su desarrollo requirió un considerable esfuerzo y dedicación, desde el diseño hasta la implementación del sistema de control.


 Aunque es un diseño experimental, su desempeño supera las expectativas iniciales y demuestra el potencial para integrar movimiento, estética y funcionalidad en proyectos dinámicos.

<h3><b>Fabricación:</b></h3>
<h3><b>Procesos utilizados:</b></h3>

Corte láser: polígonos de acrílico.


Impresión 3D: patas o soportes para los prototipos y soportes para componentes.


Router CNC: fresado de base de aluminio y molde para tapas.


Software Utilizado:


Diseño 2D y 3D: Autodesk Fusion 360 para el modelado y preparación de archivos e INKescape para el corte laser.


Partes y sistemas que se fabricaron:


Las partes y sistemas fueron fabricados utilizando las herramientas y recursos disponibles en el laboratorio.


Varilla Roscada y Eje Móvil: Generación de movimiento lineal en la estructura.



Motor de 12 V con Engranaje de Reducción: Uso, Impulsa el mecanismo de movimiento lineal tipo eje z de impresora.


<h3><b>Lista de materiales:</b></h3>
  
  ![](../images/proyecto_f/materiales2.jpg)



  
  <h3><b>Preguntas que se respondieron:</b></h3>
  

¿Es posible desarrollar superficies inflables con control estructurado?


Sí, mediante el uso de PVC flexible y técnicas de soldadura adecuadas, es viable crear estructuras inflables controladas electrónicamente.


¿Puede el origami tener aplicaciones prácticas en estructuras dinámicas?


Sí, adaptando patrones de origami a materiales rígidos y combinándolos con sistemas de movimiento precisos, se pueden desarrollar estructuras funcionales y dinámicas.


¿Cómo contribuyen la fabricación digital y los materiales reciclados a la innovación en construcción?


La fabricación digital permite precisión y personalización en el diseño, mientras que el uso de materiales reciclados promueve la sostenibilidad y reducción de residuos.

<h3><b>¿Qué funcionó? ¿Qué no?</b></h3>

Prototipo 1: Superficies Inflables Geométricas


Funcionó:


Diseño y Estética: La estructura inflable logró el movimiento y apariencia deseada.


Control Electrónico: Sincronización exitosa entre inflado e iluminación.


Control Mecánico: Buen funcionamiento de compresor de aire y válvula de escape.


No funcionó:


Problemas Iniciales de Sellado: Las primeras técnicas de soldadura no lograron la hermeticidad.


Control de Presión: Dificultades para limitar el tiempo de inflado.


Expansión de la bolsa: Dificultad para mantener estable el perímetro.

<h3><b>Prototipo 2: Estructuras Origami Extensibles</b></h3>

Funcionó:


Mecánica de Movimiento: El servomotor con reducción proporcionó el movimiento preciso.


Integración de Electrónica: La placa controla correctamente los grados de movimiento.


No funcionó:


Motores Inadecuados: Los motores NEMA 17 resultaron complejos a la hora de ajustar y programar. Luego de muchos intentos decidí cambiar a un motor DC con reducción.


Límite: El final de carrera requirió numerosos ajustes y programación de botones.


Programación: Mi falta de experiencia en programación dificulto llegar al ajuste deseado.


