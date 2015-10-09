/**

Copyright (c) 2014-2015 "M-Way Solutions GmbH"
FruityMesh - Bluetooth Low Energy mesh protocol [http://mwaysolutions.com/]

This file is part of FruityMesh

FruityMesh is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#pragma once

#include <Module.h>
extern "C" {
#include "neopixel.h"
}

class PingModule: public Module
{
	private:

		//Module configuration that is saved persistently (size must be multiple of 4)
		struct PingModuleConfiguration : ModuleConfiguration{
			//Insert more persistent config values here
			int pingInterval;
		};

		PingModuleConfiguration configuration;

		enum PingModuleTriggerActionMessages{
			TRIGGER_PING=0
		};

		enum PingModuleActionResponseMessages{
			PING_RESPONSE=0
		};

	public:
		PingModule(u16 moduleId, Node* node, ConnectionManager* cm, const char* name, u16 storageSlot);

		void ConfigurationLoadedHandler();

		void ResetToDefaultConfiguration();

		void TimerEventHandler(u16 passedTime, u32 appTimer);

		//void BleEventHandler(ble_evt_t* bleEvent);

		void ConnectionPacketReceivedEventHandler(connectionPacket* inPacket, Connection* connection, connPacketHeader* packetHeader, u16 dataLength);

		//void NodeStateChangedHandler(discoveryState newState);
		LedWrapper* LedBlue;
	int lastPingTimer = 0;
	neopixel_strip_t m_strip;
	uint8_t dig_pin_num = 15;
	uint8_t leds_per_strip = 12;
	uint8_t error;
	uint8_t led_to_enable = 5;
	uint8_t red[3] = {255, 0, 0} ;
	uint8_t green[3] = {0, 255, 0} ;
	uint8_t blue[3] = {0, 0, 255} ;
		bool TerminalCommandHandler(string commandName, vector<string> commandArgs);
};
