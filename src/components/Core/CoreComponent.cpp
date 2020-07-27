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

#include "CoreComponent.h"
#include "ComponentSystem/IComponentManager.h"
#include "PingResult.h"
#include "ContextManager.h"
#include "CommandManager.h"
#include "EditorManager.h"
#include "Core.h"
#include "IRouteEngine.h"
#include "IPingEngineFactory.h"
#include <QDebug>

void CoreComponent::initialiseEvent()
{
    qRegisterMetaType<FizzyAde::Core::PingResult>("FizzyAde::Core::PingResult");
    qRegisterMetaType<FizzyAde::Core::RouteList>("FizzyAde::Core::RouteList");
    qRegisterMetaType<QHostAddress>("QHostAddress");
    qRegisterMetaType<FizzyAde::Core::IPingEngineFactory *>("FizzyAde::Core::IPingEngineFactory *");

    FizzyAde::ComponentSystem::addObject(new FizzyAde::Core::Core());
    FizzyAde::ComponentSystem::addObject(new FizzyAde::Core::ContextManager());
    FizzyAde::ComponentSystem::addObject(new FizzyAde::Core::CommandManager());
}

void CoreComponent::initialisationFinishedEvent()
{
    auto core = FizzyAde::ComponentSystem::getObject<FizzyAde::Core::Core>();

    connect(FizzyAde::Core::IContextManager::getInstance(), &FizzyAde::Core::IContextManager::contextChanged, [&] (int newContext, int oldContext) {
        Q_UNUSED(oldContext)
        FizzyAde::Core::ICommandManager::getInstance()->setContext(newContext);
    });

    core->open();
}
