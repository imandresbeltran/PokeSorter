#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include "ListadoPokemon.h"
#include "ProcesarArchivo.h"
class OrdenarListado
{
    struct Node
    {
        ListadoPokemon data;
        Node* next;
    };


private:
    Node* Inicio = nullptr;

public:

    //Ordenamiento QuickSort Nombre
    ListadoPokemon* startQuickSort(ListadoPokemon Info[], int menor, int mayor)
    {
        QuickSort(Info, menor, mayor);
        return Info;
    }

    void QuickSort(ListadoPokemon Info[], int menor, int mayor)
    {
        if (menor < mayor)
        {
            int pi = QuickSortPartition(Info, mayor, menor);

            QuickSort(Info, menor, pi - 1);
            QuickSort(Info, pi + 1, mayor);
        }
    }

    void swap(ListadoPokemon* a, ListadoPokemon* b)
    {
        ListadoPokemon t = *a;
        *a = *b;
        *b = t;
    }

    int QuickSortPartition(ListadoPokemon Info[], int mayor, int menor)
    {

        std::string pivote = Info[mayor].NombreP;

        int i = (menor - 1);  // Index of smaller element

        for (int j = menor; j <= mayor; j++)
        {
            // If current element is smaller than or
            // equal to pivot
            if (Info[j].NombreP < pivote)
            {
                i++;    // increment index of smaller element
                swap(&Info[i], &Info[j]);
            }
        }

        swap(&Info[i + 1], &Info[mayor]);
        return (i + 1);
    }
    //Ordenamiento Selection Sort Generacion y Kdex
    ListadoPokemon* SelectionSort(ListadoPokemon Info[], int mayor, int menor)
    {
        int restaconteo = mayor;

        for (int i = 0; i < mayor; i++)
        {
            int pivote = Info[i].Generacion;
            int pivoteAux = Info[i].UnicNumber;
            int help = 0;

            for (int j = (i + 1); j <= restaconteo - 1; j++)
            {
                if (Info[j].Generacion < pivote)
                {
                    help = j;
                    pivote = Info[j].Generacion;
                }
                else if (Info[j].Generacion == pivote)
                {
                    if (Info[j].UnicNumber < pivoteAux)
                    {
                        help = j;
                        pivoteAux = Info[j].UnicNumber;
                    }
                }
                if (j == restaconteo - 1 && help != 0)
                {
                    swap(&Info[i], &Info[help]);
                }
            }
        }
        return Info;
    }
    //Ordenamiento Shell Sort

    ListadoPokemon* ShellSort(ListadoPokemon Info[], int mayor, int menor)
    {
        int intervalo = mayor / 2;
        int guia = 0;

        while (intervalo > 0 && intervalo < mayor)
        {
            int suma = intervalo;
            if (suma == 0)
            {
                suma = 1;
            }

            for (int j = 0; j < mayor; j = j + intervalo)
            {
                if (suma < mayor)
                {
                    if (Info[j].UnicNumber > Info[suma].UnicNumber)
                    {
                        swap(&Info[j], &Info[suma]);
                    }
                    suma = suma + intervalo;
                }

            }
            intervalo = intervalo / 2;
        }
        return Info;
    }


    int contador()
    {
        int conteo = 0;
        Node* Cantidad = Inicio;
        while (Cantidad) {
            conteo++;
            Cantidad = Cantidad->next;
        }
        return conteo;
    }

    void AgregaraLista(Node* lineas)
    {
        Node* ValNuevo = new Node();
        ValNuevo->data.UnicNumber = lineas->data.UnicNumber;
        ValNuevo->data.NombreP = lineas->data.NombreP;
        ValNuevo->data.Generacion = lineas->data.Generacion;

        if (lineas->data.NombreP != "" && lineas->data.NombreP != " ")
        {
            if (Inicio == nullptr)
            {
                ValNuevo->next = nullptr;
                Inicio = ValNuevo;
            }
            else
            {
                Node* Moment = Inicio;
                while (Moment->next)
                {
                    Moment = Moment->next;
                }
                Moment->next = ValNuevo;
            }
        }
    }

    Node* LeerArchivo(std::string nombre) {
        std::fstream archivo;
        int totalLines = 0;
        archivo.open(nombre, std::ios_base::in);
        std::string linea;
        char delimitador = ',';
        static Node Poke[100];
        while (archivo.good())
        {
            getline(archivo, linea);

            std::stringstream X(linea);
            Node* lineas = new Node;
            int countT = 0;
            std::string lineaT = "";
            std::string Espacios = "";

            while (getline(X, lineaT, delimitador)) {
                if (countT == 0) {

                    lineas->data.UnicNumber = std::stoi(lineaT);
                }
                if (countT == 1) {
                    Espacios = "";
                    //Validacion de espacios iniciales
                    for (size_t i = 0; i < lineaT.length(); i++)
                    {
                        if (i < 2 && lineaT[i] == ' ')
                        {
                        }
                        else
                        {
                            Espacios += lineaT[i];
                        }
                    }
                    lineas->data.NombreP = Espacios;
                }
                if (countT == 2) {

                    lineas->data.Generacion = std::stoi(lineaT);
                }
                countT = countT + 1;
            }
            totalLines = totalLines + 1;
            AgregaraLista(lineas);
        }
        archivo.close();
        return Poke;
    }

    std::string ImprimirPokemons()
    {
        std::string Mostrar = "";
        Node* Pokem = new Node();
        Pokem = Inicio;
        while (Pokem)
        {
            std::string UnicNumber = "";
            std::string Generacion = "";

            System::String^ Num = Pokem->data.UnicNumber.ToString();

            for (size_t i = 0; i < Num->Length; i++)
            {
                UnicNumber += Num[i];
            }

            System::String^ Gen = Pokem->data.Generacion.ToString();

            for (size_t i = 0; i < Gen->Length; i++)
            {
                Generacion = Gen[i];
            }

            Mostrar += UnicNumber + ", " + Pokem->data.NombreP + ", " + Generacion + "\r\n";
            Pokem = Pokem->next;
        }
        return Mostrar;


    }

    ListadoPokemon* Almacenar()
    {
        static ListadoPokemon Info[200];
        int conteo = 0;
        Node* Change = new Node;
        Change = Inicio;

        while (Change)
        {
            Info[conteo].Generacion = Change->data.Generacion;
            Info[conteo].NombreP = Change->data.NombreP;
            Info[conteo].UnicNumber = Change->data.UnicNumber;
            conteo++;
            Change = Change->next;
        }
        return Info;
    }
};

