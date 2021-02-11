#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_enviosFromText(FILE* pFile , LinkedList* pArrayListEmployee);




#endif // PARSER_H_INCLUDED
