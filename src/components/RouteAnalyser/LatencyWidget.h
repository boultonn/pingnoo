/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of Pingnoo
 *
 * Created by Adrian Carpenter on 13/12/2020.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NEDRYSOFT_LATENCYWIDGET_H
#define NEDRYSOFT_LATENCYWIDGET_H

#include <QWidget>
#include <QColor>

class QPaintEvent;

namespace Nedrysoft::RouteAnalyser {
    /**
     * @brief       The LatencyWidget is a widget that draws text in a rounded rectangle.
     */
    class LatencyWidget :
            public QWidget {

        private:
            Q_OBJECT

        public:
            Q_PROPERTY(QString text READ text WRITE setText)
            Q_PROPERTY(QColor colour READ colour WRITE setColour)

        public:
            /**
             * @brief       Constructs a new LatencyWidget instance which is a child of the parent.
             *
             * @param[in]   parent the owner widget.
             */
            LatencyWidget(QWidget *parent=nullptr);

            /**
             * @brief       Sets the text to be displayed on the widget.
             *
             * @param[in]   text the displayed text.
             */
            void setText(QString text);

            /**
             * @brief       Returns the current text value.
             *
             * @returns     The text value.
             */
            QString text();

            /**
             * @brief       Sets the current colour of the widget.
             *
             * @param[in]   colour the widget colour.
             */
            void setColour(QColor colour);

            /**
             * @brief       Returns the current colour of the widget
             *
             * @returns     the widget colour.
             */
            QColor colour();

        private:
            /**
             * @brief       Returns a colour that contrasts with the given colour.
             *
             * @details     Determines the lightness of the colour, anything below 0.5 the function will return
             *              white, anything above 0.5 the function returns black.
             *
             * @param[in]   colour the colour to get the contrast colour for.
             *
             * @returns     the contrast colour.
             */
            QColor getContrastColour(QColor colour);

        protected:
            /**
             * @brief       Reimplements: QWidget::paintEvent(QPaintEvent *event).
             *
             * @param[in]   event the event information.
             */
            void paintEvent(QPaintEvent *event);

        private:
            QColor m_colour;
            QString m_text;
    };
};

#endif //NEDRYSOFT_LATENCYWIDGET_H
