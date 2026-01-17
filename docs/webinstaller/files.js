const firmwareData = {
    "marauder": {
        "name": "Mayhem Marauder",
        "versions": ["1.4.4", "0.13.6"],
        "manifests": {
            "1.4.4": "marauder_1.4.4/manifest.json",
            "0.13.6": "marauder_0.13.6/manifest.json"
        },
        "downloads": {
            "1.4.4": {
                "fap": { "path": "marauder_1.4.4/faps/mayhem_marauder.fap", "name": "mayhem_marauder.fap" },
                "elf": { "path": "marauder_1.4.4/esp32cam_marauder.ino.elf", "name": "esp32cam_marauder.ino.elf" },
                "bins": [
                    { "path": "marauder_1.4.4/esp32cam_marauder.ino.bin", "name": "esp32cam_marauder.ino.bin" },
                    { "path": "marauder_1.4.4/esp32cam_marauder.ino.bootloader.bin", "name": "bootloader.bin" },
                    { "path": "marauder_1.4.4/esp32cam_marauder.ino.partitions.bin", "name": "partitions.bin" },
                    { "path": "marauder_1.4.4/boot_app0.bin", "name": "boot_app0.bin" }
                ]
            },
            "0.13.6": {
                "fap": null,
                "elf": { "path": "marauder_0.13.6/esp32cam_marauder.ino.elf", "name": "esp32cam_marauder.ino.elf" },
                "bins": [
                    { "path": "marauder_0.13.6/esp32cam_marauder.ino.bin", "name": "esp32cam_marauder.ino.bin" },
                    { "path": "marauder_0.13.6/esp32cam_marauder.ino.bootloader.bin", "name": "bootloader.bin" },
                    { "path": "marauder_0.13.6/esp32cam_marauder.ino.partitions.bin", "name": "partitions.bin" },
                    { "path": "marauder_0.13.6/boot_app0.bin", "name": "boot_app0.bin" }
                ]
            }
        },
        "changelog": [
            { "version": "v1.4.4", "date": "2025-04-29", "changes": ["Updated Marauder to latest version", "Updated Marauder companion to v0.7.2"] },
            { "version": "v0.13.6", "date": "2023-12-20", "changes": ["Updated Marauder to latest version", "Updated Marauder companion to v0.6.6"] },
            { "version": "v0.13.5 r1", "date": "2023-12-14", "changes": ["Enabled bluetooth functionality for Marauder"] },
            { "version": "v0.13.5", "date": "2023-12-04", "changes": ["Updated Marauder to latest version", "Updated Marauder companion to v0.6.5"] },
            { "version": "v0.13.4", "date": "2023-11-19", "changes": ["Updated Marauder to latest version"] },
            { "version": "v0.13.3", "date": "2023-11-08", "changes": ["Updated Marauder to latest version", "Updated Marauder companion to v0.6.4"] },
            { "version": "v0.12.0", "date": "2023-09-14", "changes": ["All the apps will have the version number now in the name", "Updated Marauder code to latest version", "Removed EvilPortal companion, since Marauder implements it now"] }
        ]
    },
    "bt_audio": {
        "name": "FatherDivine's BT Audio",
        "versions": ["0.1.0"],
        "manifests": {
            "0.1.0": "bt_audio_0.1.0/manifest.json"
        },
        "downloads": {
            "0.1.0": {
                "fap": { "path": "bt_audio_0.1.0/faps/bt_audio.fap", "name": "bt_audio.fap" },
                "elf": { "path": "bt_audio_0.1.0/firmware.elf", "name": "firmware.elf" },
                "bins": [
                    { "path": "bt_audio_0.1.0/firmware.bin", "name": "firmware.bin" },
                    { "path": "bt_audio_0.1.0/bootloader.bin", "name": "bootloader.bin" },
                    { "path": "bt_audio_0.1.0/partitions.bin", "name": "partitions.bin" },
                    { "path": "bt_audio_0.1.0/boot_app0.bin", "name": "boot_app0.bin" }
                ]
            }
        },
        "changelog": [
            { "version": "v0.1.0", "date": "", "changes": ["First version"] }
        ]
    }
};
