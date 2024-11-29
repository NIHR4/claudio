# Claudio

## Resumen
- Transpilador Clarion++ a Clarion (source-to-source) que permite convertir codigo Clarion++; lenaguje que extiende las capcidades de Clarion con una sintaxis mas moderna y expresiva.

## Motivación y Problema a Resolver
- **Descripción del problema:** <br>
  El lenguaje Clarion es anticuado y carese de multiples caracteristicas, consideradas basicas en lenguajes contemporaneos. Dentro de las cuales destaca (pero no se limita a):
    - Solo es posible declarar variables en un segmento de datos definido en el inicio de un procedimiento
    - Es dificil determinar el scope de las variables debido a que Clarion no hace uso de corchetes para delimitar scope
	- No es posible encadenar multiples operadores en una sola linea
	- Clarion no utiliza `;` para determinar el fin de un enunciado, lo cual puede dificultar la lectura del codigo fuente
	

- **Importancia:** 
El lenguaje de Clarion tiene multiples deficiencias, y podria considerarse un "producto de sus tiempos", el cual no se ha modernizado a los estandares actuales. El codigo fuente en Clarion es muy poco expresivo, lo cual resulta en muchas lineas de codigo para realizar tareas comunes, y por consequencia codigo dificil de leer y mantener.
- **Casos de uso:** 

## Objetivos del Proyecto
- **Objetivo 1:**
  - Crear una forma sencilla de utilizar y adaptar código para Clarion.
- **Objetivo 2:**
  - Declaracion de variables en cualquier punto de una funcion.
- **Objetivo 3:**
  - Delimitacion de scope utilizando brackets (`{}`).
- **Objetivo 4**
  - Procesamiento correcto de tokens en el lenguaje

## Revisión del Estado del Arte
- **Compiladores similares:**
TypeScript es un lenguaje de programación de alto nivel, gratuito y de código abierto desarrollado por Microsoft que agrega tipado estático con anotaciones de tipo opcionales a JavaScript. Está diseñado para el desarrollo de aplicaciones grandes y se transpila a JavaScript.

- **Limitaciones de soluciones actuales:**
Al momento de escribir este documento, el unico compilador para codigo fuente Clarion ES el compilador oficial de Top Speed.
- **Justificación del nuevo compilador:**
Clarion es un lenguaje de codigo cerrado, y no hay manera agregar caracteristicas extras al lenguaje en si por medio de un fork o extensiones al compilador. Por lo cual, la unica forma de corregir las carencias del lenugaje señaladas en este documento, es por medio de un transpilador.

## Arquitectura y Diseño del Compilador
- **Diagrama de bloques:**
![diagramaBloques]("https://github.com/NIHR4/claudio/blob/master/images/diagramabloques.png")
- **Explicación del flujo de datos:**
El flujo de datos comienza con la entrada del código fuente en texto plano, que pasa por el análisis léxico para convertirlo en una lista de tokens, identificando palabras clave, identificadores, operadores y literales. Luego, estos tokens son procesados en el análisis sintáctico, donde se verifica que cumplan las reglas gramaticales del lenguaje y se construye un Árbol de Sintaxis Abstracta (AST). Este árbol pasa al análisis semántico, donde se valida la consistencia del programa, incluyendo tipos de datos, alcance de variables y uso correcto de operaciones. Finalmente, el AST validado se utiliza para generar código ejecutable o intermedio, garantizando que el programa es correcto y funcional antes de su ejecución.
- **Decisiones de diseño:**
El diseño del lenguaje se basa en principios que buscan equilibrio entre simplicidad, flexibilidad, y legibilidad.

- Cada elemento principal del lenguaje se define de forma independiente, lo que facilita su comprensión y permite extender el lenguaje en el futuro
- La gramática fue diseñada para evitar ambigüedades al analizar el código, favoreciendo la construcción de compiladores o intérpretes eficientes.
- Declaraciones como function permiten construir aplicaciones modulares y reutilizables.
- 
## Análisis Léxico
- **Análisis léxico:** 
  - Tokenización, identificación de palabras clave, operadores, etc.
- **Ejemplos:**
```
function MyProcedure() {
  
  for(int64 i=0; i < 10; i++) {
    MessageBox(i);
  }
}
```

```
function int MyFunction(int a, int b) {
  return a + b;
}
```
```
procedure ComplicatedExpression(string value) {
  functionCall((value == "hello") ? "truthyVal" : "falsyVal")
}
```

## Análisis Sintáctico

- **Análisis sintáctico:** 
  - Uso de gramáticas y árboles sintácticos.
Programa y lista de declaraciones
```
<Programa> ::= <StatementList>
<StatementList> ::= <Statement> <StatementList> | ε | <EOF>
```
Declaraciones (Statements)
```
<Statement> ::= <identifier> <Statement_tail> ";" 
              | <Expression> 
              | <if_statement> 
              | <while_statement> 
              | <for_statement> 
              | <procedure_statement> 
              | <return_statement> 
              | <break_statement> 
              | <declaration_statement>

<Statement_tail> ::= "=" <Expression> | <Expression_tail>
<Expression_tail> ::= <binary_operator> <term> <Expression_tail> | ε
```
**Declaraciones específicas**
Declaración de asignación
```
<assignment_statement> ::= <identifier> "=" <Expression> ";"
```
Declaración de declaración (declaration statement)
```
<declaration_statement> ::= <type> <identifier> "=" <Expression> ";"
```
Incremento
```
<increment_expression> ::= <identifier> "++"
```
***Expresiones**
Expresión general
```
<Expression> ::= <binary_expression> 
               | <unary_expression> 
               | <literal_expression> 
               | "(" <Expression> ")"
```
Expresión binaria
```
<binary_expression> ::= <term> <binary_expression'>
<binary_expression'> ::= <binary_operator> <term> <binary_expression'> | ε
<binary_operator> ::= "+" | "-" | "*" | "/" | ">" | "<" | "==" | "!="
```
Expresión unaria
```
<unary_expression> ::= <unary_operator> <Expression>
<unary_operator> ::= "-" | "!" | "++" | "--"
```
Expresión literal
```
<literal_expression> ::= <integer_literal> | <string_literal>
<integer_literal>  
<string_literal>  
```
**Componentes internos de expresiones**
Término y factor
```
<term> ::= <factor> <term'>
<term'> ::= "*" <factor> <term'> | "/" <factor> <term'> | ε
<factor> ::= <integer_literal> | <identifier>
```
Identificadores
```
<identifier> ::= <letter> <letter_or_digit>*
<letter> ::= [a-zA-Z]
<letter_or_digit> ::= <letter> | [0-9]
```
**Estructuras de control**
If-Else
```
<if_statement> ::= "if" "(" <Expression> ")" <Statement> <if_statement'>
<if_statement'> ::= "else" <Statement> | ε
```
While
```
<while_statement> ::= "while" "(" <Expression> ")" <Statement>
```
For
```
<for_statement> ::= "for" "(" <assignment_statement> ";" <Expression> ";" <increment_expression> ")" "{" <Statement>* "}"
```
**Funciones y procedimientos**
```
<procedure_statement> ::= "function" <identifier> "(" <parameter_list> ")" "{" <Statement>* "}"
<parameter_list> ::= <type> <identifier> ("," <type> <identifier>)* | ε
```
Declaraciones adicionales
Return
```
<return_statement> ::= "return" [<Expression>] ";"
```
Break
```
<break_statement> ::= "break" ";"
```
- **Ejemplos:**

## Análisis Semántico

- **Análisis sintáctico:** 
  - Uso de gramáticas y árboles sintácticos.

- **Ejemplos:**

## Pruebas y Validación

- **Metodología de pruebas:**
  Creación de archivos de código que utilicen las reglas de producción y semánticas para comprobar funcionamiento.
  Creación de archivos de código que fallen en las relgas de producción o en las semánticas para comprobar funcinamiento
- **Resultados obtenidos:**
  Se indentificó que en las estructuras de control (if-else, while y for), el diseño de las reglas de producción fue incorrecto ya que se pusieron como expresiones elemetnos que tuvieron que haber sido expresiones booleanas, por lo que a pesar de que teóricamente funcionan, no están de la forma correcta para esas estructuras.
- **Casos de prueba específicos:**
  ```
  function main(int64 argc) {
  int64 x = 5; }
  ```
  ```
  function sum(int x){
  int y=0;
	for(int i= 0; i<x; i++){
		y= y + i;
  	}
  	return y;
  }
  ```
## Herramientas y Entorno de Desarrollo
- **Lenguajes de programación utilizados:**
  - C++ 23
  - Python

- **Herramientas de desarrollo:**
 - CMake
 - vcpkg
 - Visual Studio 2022
 - VSCode
 - Antlr4

- **Entorno de pruebas y simulación:** Pruebas en Windows 11 que se hicieron manualmente generando archivos de código a probar.

## Demostración
- **Ejemplo de código fuente:**
  ```
  function main(){
	int x = 10;
	int y = 5;
	string message = "Hello, World!";
	x = x + y;
	y++;
	if (x > y) {
	    x = x * 2;
	} else {
	    x = x / 2;
	}
	while (x < 50) {
	    x = x + 5;
	}
	for (int i = 0; i < 10; i++) {
	    x = x + i;
	}
	function multiply(int a, int b) {
	    return a * b;
	}
	int result = multiply(x, y);
	int z = -result;
	string greeting = "Result is: ";
	print(greeting + z);
	while (z > 0) {
	    z = z - 1;
	    if (z == 10) {
	        break;
	    }
	}
	return;
   }
  ```
- **Proceso de compilación:**
- **Ejecución del código compilado:**

## Desafíos y Soluciones
- **Problemas técnicos o de diseño:**
  Las primeras versiones de nuestras reglas de producción no cumplían con las condiciones para relizar parsing LL1, por lo que tuvimos que hacer constante rediseño y ajuste a nuestras reglas de producción
- **Estrategias adoptadas para superar desafíos:**
  Cambiamos la forma en la que nos repartimos las tareas del proyecto, ya que tuvimos que haber hecho muchas cosas en conjunto y comunicándonos más para entender correctamente la teoría. También limitamos el scope de nuestro proyecto para poder adaptarnos a las limitaciones de tiempo.
- **Lecciones aprendidas:**
	• Importancia de la comunicación en equipo
	• Distribución de carga de trabajo
	• Delimitación de objetivos en base a limitaciones
	• Diseño en base a necesidades
	• Actualizar documentación
## Conclusiones y Trabajo Futuro
- **Resumen de objetivos cumplidos:**
• Crear una forma sencilla de utilizar y adaptar código para Clarion. **CUMPLIDO**
• Declaración de variables en cualquier punto de una función. **CUMPLIDO**
• Delimitación de scope utilizando brackets ({}). **OMITIDO**
• Realizar múltiples operaciones en la misma linea **CUMPLIDO**
- **Evaluación del desempeño:**
  Consideramos que, a pesar de cumplir nuestros objetivos, hubo muchos detalles que se pudieron haber mejorado con una mejor comunicación para poder aplicar los conocimientos teóricos que teníamos de forma efectiva.
- **Propuestas para mejoras futuras:**
Debido a las limitaciones de tiempo, el compilador puede mejorar bastante, agregando más funcionalidades y mejorando las actuales, para esto a futuro se podríá hacer lo siguiente:
	- Mejorar el parser para expresiones declarativas que tengan condiciones
 	- Mejor trato de las scopes dentro del código
  	- Implementación de más tipos de declaraciones.
## Preguntas y Discusión
- Espacio para responder preguntas y discusión sobre el proyecto.

## Referencias
- **Fuentes citadas:** 
Staff, A. (2012, October 3). Microsoft TypeScript: the JavaScript we need, or a solution looking for a problem? Ars Technica. https://arstechnica.com/information-technology/2012/10/microsoft-typescript-the-javascript-we-need-or-a-solution-looking-for-a-problem/
