#include "FUNCIONES.cpp"

using namespace std;

/* si se quiere editar las rutas por un archivo de texto editarla por favor en el
archivo llamado rutas.txt ubicado en la carpeta llamada rutas siguiendo las indicaciones que se
indican en el archivo rutas.txt */

/*ingresar el documento topologia.txt en el archivo llamado rutas y dentro del documento topologia.txt
 porfavor que halla un comentario inicial terminando en "." y que cada ruta termine tambien en "."
 ej:
  HOLA.
  AB,5.
  BA,5.
*/

int main()
{
    bool x=true; //-> esta x permite que el proceso siga o termine, es nuestra llave de flujo  en el codigo ya que cuando cambia a false todo termina
    while(x){
        system("CLS");
        x=Menu_();}
    return 0;
}

