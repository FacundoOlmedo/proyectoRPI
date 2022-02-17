# Proyecto final UTN FRC

## Proyecto Final de Tecnicas Digitales II 4to año - Ingenieria Electronica - Universidad Tecnologica Nacional FRC

Este proyecto consiste en integrar dichos ejercicios de la siguiente manera:

- Realice un programa a fin de que el usuario pueda seleccionar desde un menú, una de ocho secuencias de luces posibles. Cuatro de ellas serán comunes para todos los proyectos y son: "El auto fantástico", "El choque", "La apilada" y "La carrera". Las otras cuatros serán propias de cada grupo y se deberán implementar dos de ellas con algoritmo y las dos restantes por medio de la técnica de tablas de datos.

- Implemente el control de acceso a este menú mediante password.

- Cada vez que el usuario seleccione una secuencia el programa deberá cambiar la pantalla para indicar cual secuencia está ejecutándose y como hacer para salir de la misma. Al optar por abandonar la actual, el programa deberá regresar al menú principal inmediatamente sin completar la secuencia que se está desarrollando y apagando todas las luces.

- Permita la posibilidad de controlar la velocidad de cada secuencia. Presionando la flecha hacia arriba se incrementará la velocidad y presionando la flecha hacia abajo se reducirá. Introduzca el sensado de las teclas oprimidas en el lugar apropiado de su programa a fin de percibir la reacción del sistema en forma inmediata, independiente de la velocidad actual. La velocidad ajustada en cada secuencia deberá conservarse entre llamadas a diferentes secuencias.

- El valor inicial correspondiente a la velocidad de las secuencias deberá ingresarse mediante la lectura del estado de los potenciómetros que están conectados a las entradas analógicas del conversor A/D.

- Generar una opción en el programa que permita establecer dos modos de trabajo: local y remoto. En modo local las secuencias de luces se ejecutarán en los leds que se encuentran en el hardware adicionado a la placa Raspberry donde se ejecuta el programa. Existen dos opciones para el modo remoto dependiendo de la disponibilidad de hardware de cada grupo, hacer una de las dos opciones siguientes:

  - En modo remoto las secuencias se ejecutarán sobre el hardware adicional colocado en otra Raspberry y conectada a la que ejecuta el programa mediante un cable serie RS-232. Se podrá usar el mismo programa para implementar esta opción en las dos Raspberry o realizar uno principal y otro secundario.

  - En modo remoto la selección desde el menú de la secuencia de luces a ejecutarse y control de velocidad se harán desde una PC que se encontrará conectada mediante un cable serie RS-232 a la Raspberry.

- Como opción genere una sección destinada a establecer las velocidades iniciales de las secuencias realizando el ajuste de los potenciómetros.

## Condiciones de presentación

El proyecto deberá ser presentado en la fecha establecida oportunamente (no deberá en ningún caso superar la última semana de clase), y estará en condiciones de hacerlo todo programa que cumpla con las especificaciones mínimas enunciadas anteriormente. El trabajo se llevará a cabo en grupo de dos estudiantes, que al momento de la presentación deberán estar en condiciones de contestar indistintamente cualquier pregunta, demostrando en todo momento precisión, claridad conceptual de los temas involucrados en el proyecto, y contribución personal al programa. Hay que recordar que el proyecto es una evaluación con una modalidad diferente a la tradicional, pero evaluación al fin. Por lo tanto la nota es personal, pudiendo darse el caso eventualmente de diferente notas entre los miembros de un mismo equipo, llegando incluso al aplazo de alguno de ellos.

Al proyecto se le podrán agregar toda clase de opciones que sean pertinentes con lo esbozado anteriormente y que significará una mejor evaluación. Estas características deberán ser claramente remarcadas en la presentación.

Si por cualquier motivo no se presentara el proyecto en la fecha indicada, se deberá presentar antes del examen final como requisito de la parte práctica del mismo.

## Secuencias de luces

Auto fantástico: una luz que se desplaza de izquierda a derecha y de derecha a izquierda.

El choque: una luz desde la izquierda y otra desde la derecha comienzan su recorrido en forma opuesta y por lo tanto al medio se cruzan y continúan hasta los extremos opuestos. En la visualización de la misma parece que las luces chocan y se repelen.

La apilada: Una luz arranca de izquierda a derecha y cuando alcanza el extremo derecho, parpàdea y se queda encendida en la última posición; a partir de allí una nueva luz comienza su recorrido desde la izquierda y se desplaza hacia la derecha hasta llegar a la posición anterior a la que está fija, parpadea y también se queda quieta como la anterior. Ahora son dos las luces quietas y se repite el mismo proceso para una nueva luz arrancando por la izquierda y llegando a la posición anterior a las dos quietas. La secuencia termina cuando los ocho lugares han sido ocupados de la forma descripta.

La carrera: Una luz arranca por la izquierda a una determinada velocidad, y cuando va por la mitad del recorrido arranca una nueva luz por la izquierda pero al doble de velocidad lo que produce que arriben al extremo derecho al mismo tiempo.

La técnica de tabla de datos consiste en simplemente un bucle de programa que saca por los puertos de salida el contenido de una tabla preestablecida con valores que reproducen la secuencia deseada.

Saludos
