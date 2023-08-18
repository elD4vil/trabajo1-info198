# Trabajo 1: SistemaS Operativos (INFO198)

En este trabajo, mi propuesta consiste en crear una interfaz de usuario basada en la información de una base de datos almacenada en un archivo de texto. A modo de ejemplo, el archivo tiene la siguiente estructura:

Matias;1,2,3

Juan;2,3,4

Sebastian;1 


En esta estructura, cada línea representa un usuario seguido de una serie de números que corresponden a las opciones disponibles para ese usuario en la interfaz.

# Ejecucion

Para poder ejecutar este código, primero debemos compilarlo. Un ejemplo de cómo hacerlo es ejecutando el siguiente comando en la terminal:

```g++ -o app app.cpp```.

Una vez que el código esté compilado, para ejecutarlo será necesario proporcionar una entrada desde la consola que cumpla con el siguiente formato:


```./app -u Juan -v 1,2,3```


Donde el primer argumento representa el nombre de usuario y el segundo argumento es un vector con varios numeros que `deben estar separados por comas`, que puede ser los valores enteros que usted deseé.

Es importante tener en la misma carpeta el archivo de texto llamado **basededatos.txt**, donde se guardarán los diferentes datos, tal como se mostró en el ejemplo anterior.

Si el Usuario es valido entrara al interfaz. pero si el usuario no existe el codigo mandara un mensaje de error y se saldra el programa.

En la pantalla se veran las opciones disponibles, si intenta ingresar una opcion que no se muestre en la pantalla, esto generar un error con su respectivo mensaje y pidiendo nuevamente el ingreso de alguna opcion.