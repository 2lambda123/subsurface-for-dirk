// SPDX-License-Identifier: GPL-2.0
// Note: this header file is used by the undo-machinery and should not be included elsewhere.

#ifndef COMMAND_DEVICE_H
#define COMMAND_DEVICE_H

#include "command_base.h"
#include "core/device.h"

struct device;

// We put everything in a namespace, so that we can shorten names without polluting the global namespace
namespace Command {

class EditDeviceNickname final : public Base {
public:
	EditDeviceNickname(const divecomputer *dc, const QString &nickname);
private:
	// for redo and undo
	int index;
	std::string nickname;

	void undo() override;
	void redo() override;
	bool workToBeDone() override;
};

} // namespace Command
#endif
