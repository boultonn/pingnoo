/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of pingnoo (https://github.com/fizzyade/pingnoo)
 * An open source ping path analyser
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

#ifndef NEDRYSOFT_PUBLICIPHOSTMASKER_PUBLICIPHOSTMASKER_H
#define NEDRYSOFT_PUBLICIPHOSTMASKER_PUBLICIPHOSTMASKER_H

#include "ComponentSystem/IInterface.h"
#include "Core/IConfiguration.h"
#include "Core/IHostMasker.h"

#include <QObject>

namespace Nedrysoft::PublicIPHostMasker {
    /**
     * @brief       The PublicIPHostMasker class provides a host masker that redacts the public ip.
     *
     * @details     This host marker determines the public IP and then redacts any instances of it.
     */
    class PublicIPHostMasker :
            public Nedrysoft::Core::IHostMasker {

        private:
            Q_OBJECT

            Q_INTERFACES(Nedrysoft::Core::IHostMasker)

        public:
            /**
             * @brief       Masks a host name/ip.
             *
             * @detail      A IHostMasker can redact the hostname and/or host address based of a combination of
             *              host name, host address and the hop number.
             *
             *              If there is no match, then the original values are returned.
             *
             * @see         Nedrysoft::Core::IHostMasker
             *
             * @param[in]   hop the hop number.
             * @param[in]   hostName the host name to be checked.
             * @param[in]   hostAddress the host IP to be checked.
             * @param[out]  maskedHostName the masked host name.
             * @param[out]  maskedHostAddress the masked host IP.
             *
             * @returns     returns true on replacement; otherwise false.
             */
            virtual bool mask(int hop, const QString &hostName, const QString &hostAddress, QString &maskedHostName,
                              QString &maskedHostAddress);

        public:
            /**
             * @brief       Saves the configuration to a JSON object.
             *
             * @see         Nedrysoft::Core::IConfiguration::saveConfiguration
             *
             * @returns     the JSON configuration.
             */
            virtual QJsonObject saveConfiguration();

            /**
             * @brief       Loads the configuration.
             *
             * @see         Nedrysoft::Core::IConfiguration::loadConfiguration
             *
             * @param[in]   configuration the configuration as JSON object.
             *
             * @returns     true if loaded; otherwise false.
             */
            virtual bool loadConfiguration(QJsonObject configuration);

        private:
            QString m_publicIP;

    };
}

#endif // NEDRYSOFT_PUBLICIPHOSTMASKER_PUBLICIPHOSTMASKER_H
