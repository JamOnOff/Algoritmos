/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Noticia.h
 * Author: Josue Alvarez M
 *
 * Created on 2 de marzo de 2022, 18:15
 */

#ifndef NOTICIA_H
#define NOTICIA_H

#include <string.h>
#include <vector>

using namespace std;

class INoticia{
public:
    virtual string getInfo() = 0;
};

class Noticia : public INoticia{
protected:
    string titulo = "";
    string fecha = "";
    string reportero = "";

public:
    Noticia(string titulo, string fecha, string reportero) :
        titulo(titulo), fecha(fecha), reportero(reportero) {
    }

    string getFecha() const {
        return fecha;
    }

    void setFecha(string fecha) {
        this->fecha = fecha;
    }

    string getReportero() const {
        return reportero;
    }

    void setReportero(string reportero) {
        this->reportero = reportero;
    }

    string getTitulo() const {
        return titulo;
    }

    void setTitulo(string titulo) {
        this->titulo = titulo;
    }
};


class NoticiaPaper : public Noticia{
private:
    string archivo = "";
public:
    NoticiaPaper(string titulo, string fecha, string reportero, string archivo) :
    Noticia(titulo, fecha, reportero), archivo(archivo) {
    }

    string getArchivo() const {
        return archivo;
    }

    void setArchivo(string archivo) {
        this->archivo = archivo;
    }
    
    //Override
    virtual string getInfo(){
        return titulo + "\n\n" + fecha + "  " + reportero + "\n" + archivo;
    }
};

class NoticiaDigital : public Noticia{
public:
    vector<string> media;
    
    NoticiaDigital(string titulo, string fecha, string reportero) :
        Noticia(titulo, fecha, reportero){
    }

    
    //Override
    virtual string getInfo(){
        string s = "";
        
        for (string m : media) {
            s += m + "\n";
        }

        return titulo + "\n\n" + fecha + "  " + reportero + "\n" + s;
    }
};

class NoticiaRadio : public Noticia{
private:
    string audio;
public:
    NoticiaRadio(string titulo, string fecha, string reportero, string audio) :
        Noticia(titulo, fecha, reportero), audio(audio) {
    }

    string getAudio() const {
        return audio;
    }

    void setAudio(string audio) {
        this->audio = audio;
    }
    //Override
    virtual string getInfo(){
        return titulo + "\n\n" + fecha + "  " + reportero + "\n" + audio;
    }
};

#endif