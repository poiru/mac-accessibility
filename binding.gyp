{
  "targets": [
    {
      "target_name": "addon",
      "sources": [
        "addon.cc",
        "addon_mac.mm",
      ],
      "xcode_settings": {
        'OTHER_CPLUSPLUSFLAGS' : ['-std=c++14','-stdlib=libc++'],
        'OTHER_LDFLAGS': ['-stdlib=libc++'],
        'MACOSX_DEPLOYMENT_TARGET': '10.9'
      },
      "libraries": [
        "-Wl,-framework -Wl,Foundation -Wl,-framework -Wl,AppKit",
        "-mmacosx-version-min=10.9",
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
