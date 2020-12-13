/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of Pingnoo
 *
 * Created by Adrian Carpenter on 05/12/2020.
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

#ifndef NEDRYSOFT_COLOURMANAGER_H
#define NEDRYSOFT_COLOURMANAGER_H

#include <QRgb>

namespace Nedrysoft::RouteAnalyser {

    /**
     * @brief       The ColourManager class is a convenience class for getting the min, mid and max colours, these
     *              change according to light or dark mode.
     */
    class ColourManager {
        public:
            /**
             * @brief       Returns the minimum colour (low latency).
             *
             * @return      the minimum colour
             */
            static QRgb getMinColour();

            /**
             * @brief       Returns the median colour (mid latency).
             *
             * @return      the median colour
             */
            static QRgb getMidColour();

            /**
             * @brief       Returns the maximum colour (high latency).
             *
             * @return      the maximum colour
             */
            static QRgb getMaxColour();
    };
};

#endif //NEDRYSOFT_COLOURMANAGER_H
