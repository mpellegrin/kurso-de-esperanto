/*
    Kurso de Esperanto - a free multimedia course to teach yourself the
    international language.
    Copyright (C) 2000-2012 Carlos Alberto Alves Pereira
    karlo@kurso.com.br

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 3 as
    published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    Kurso de Esperanto - multrimeda komputila kurso por memlernado de
    la internacia lingvo.
    Kopirajto (C) 2000-2012 Carlos Alberto Alves Pereira
    karlo@kurso.com.br

    Tiu ĉi programo estas libera softvaro: vi povas ĝin redisdoni aŭ
    ĝin modifi laŭ la kondiĉoj de GNU-a Ĝenerala Publika Uzpermeso versio 3
    kiel publikigita de Free Software Foundation.

    Tiu ĉi programo estas disdonita kun la espero, ke ĝi estos utila,
    sed sen ia garantio; eĉ sen la implica garantio de komercebleco aŭ
    taŭgeco por specifa celo. Vidu la GNU-an Ĝeneralan Publikan Uzpermeson
    por pliaj detaloj.

    Vi devus esti ricevinta kopion de la GNU-a Ĝenerala Publika Uzpermeso
    kune kun ĉi tiu programo. Se ne, iru al <http://www.gnu.org/licenses/>.
*/

#include <QtGui/QApplication>
#include <QtCore>
#include <QFontDatabase>
#include "kurso.h"
#include "funkcioj.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Kurso4");
    Loko = QApplication::applicationDirPath();
    if (Loko.right(1) != "/")
        Loko.append("/");

    QFontDatabase::addApplicationFont(":tiparoj/DejaVuSans.ttf");
    QFontDatabase::addApplicationFont(":tiparoj/DejaVuSans-Bold.ttf");
    kurso w;
    w.show();
    Phonon::MediaObject *ludilo;
    ludilo =  Phonon::createPlayer(Phonon::MusicCategory,
                                   Phonon::MediaSource());


    if (lSxaltilo)
    {
        int iAleat6;

        QString sMp3dos;
        iAleat6 = random(2);
        if (iAleat6 == 0)
            sMp3dos = "saluton";
        else
        {
            QTime nun = QTime::currentTime();
            int horo = nun.hour();

            if ((horo >= 16) && (horo <= 20))
                sMp3dos = "vespero";
            else if ((horo >= 5) && (horo <= 11))
            {
                iAleat6 = random(2);
                if (iAleat6 == 0)
                    sMp3dos = "matenon";
                else  sMp3dos = "tagon";
            }
            else if ((horo >= 12) && (horo <= 15))
                sMp3dos = "tagon";
            else sMp3dos = "nokton";
        }

        QDir sonoj(Loko + "sonoj/");
        QStringList filtriloj;
        filtriloj << sMp3dos + "?" + mp3_finajho;
        sonoj.setNameFilters(filtriloj);
        int kvanto = sonoj.count();
        iAleat6 = random(kvanto);
        QString dosiernomo = "sonoj/" + sonoj.entryList().at(iAleat6);

        ludilo->setCurrentSource(Loko + dosiernomo);
        ludilo->play();
    }


    return a.exec();
}
