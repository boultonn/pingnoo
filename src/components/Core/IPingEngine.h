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

#ifndef NEDRYSOFT_CORE_IPINGENGINE_H
#define NEDRYSOFT_CORE_IPINGENGINE_H

#include "ComponentSystem/IInterface.h"
#include "CoreSpec.h"
#include "IConfiguration.h"
#include "PingResult.h"

#include <QHostAddress>
#include <chrono>

namespace Nedrysoft::Core {
    class IPingTarget;

    /**
     * @brief       The IPingEngine interface describes a ping engine.
     *
     * @details     An engine implements the logic of transmitting, receiving and associating replies to ping requests,
     *              it then signals when a ping result is available.  The underlying mechanism of handling the pings
     *              is hidden from the applicaton.
     */
    class NEDRYSOFT_CORE_DLLSPEC IPingEngine :
            public Nedrysoft::ComponentSystem::IInterface,
            public Nedrysoft::Core::IConfiguration {

        private:
            Q_OBJECT

            Q_INTERFACES(Nedrysoft::ComponentSystem::IInterface)
            Q_INTERFACES(Nedrysoft::Core::IConfiguration)

        public:
            /**
             * @brief       Destroys the IPingEngine.
             */
            virtual ~IPingEngine() = default;

            /**
             * @brief       Sets the measurement interval for this engine instance.
             *
             * @param[in]   interval interval time.
             *
             * @returns     returns true on success; otherwise false.
             */
            virtual bool setInterval(std::chrono::milliseconds interval) = 0;

            /**
             * @brief       Sets the reply timeout for this engine instance.
             *
             * @param[in]   timeout the amount of time before we consider that the packet was lost.
             *
             * @returns     true on success; otherwise false.
             */
            virtual bool setTimeout(std::chrono::milliseconds timeout) = 0;

            /**
             * @brief       Starts ping operations for this engine instance.
             *
             * @return      true on success; otherwise false.
             */
            virtual bool start() = 0;

            /**
             * @brief       Stops ping operations for this engine instance.
             *
             * @returns     true on success; otherwise false.
             */
            virtual bool stop() = 0;

            /**
             * @brief       Adds a ping target to this engine instance.
             *
             * @param[in]   hostAddress the host address of the ping target.
             *
             * @returns     returns a pointer to the created ping target.
             */
            virtual IPingTarget *addTarget(QHostAddress hostAddress) = 0;

            /**
             * @brief       Adds a ping target to this engine instance.
             *
             * @param[in]   hostAddress the host address of the ping target.
             * @param[in]   ttl the time to live to use.
             *
             * @return      returns a pointer to the created ping target.
             */
            virtual IPingTarget *addTarget(QHostAddress hostAddress, int ttl) = 0;

            /**
             * @brief       Removes a ping target from this engine instance.
             *
             * @param[in]   target the ping target to remove.
             *
             * @return      true on success; otherwise false.
             */
            virtual bool removeTarget(IPingTarget *target) = 0;

            /**
             * @brief       Gets the epoch for this engine instance.
             *
             * @return      the time epoch
             */
            virtual std::chrono::system_clock::time_point epoch() = 0;

            /**
             * @brief       Signal emitted to indicate the state of a ping request.
             *
             * @param[in]   result the result of a ping request.
             */
            Q_SIGNAL void result(Nedrysoft::Core::PingResult result);
    };
}

Q_DECLARE_INTERFACE(Nedrysoft::Core::IPingEngine, "com.nedrysoft.core.IPingEngine/1.0.0")

#endif // NEDRYSOFT_CORE_IPINGENGINE_H
