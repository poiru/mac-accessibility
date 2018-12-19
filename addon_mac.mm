#include "addon.h"

#import <Cocoa/Cocoa.h>

bool IsTrustedAccessibilityClient(bool prompt) {
  NSDictionary* options = @{(id)kAXTrustedCheckOptionPrompt: @(prompt)};
  return !!AXIsProcessTrustedWithOptions((CFDictionaryRef)options);
}

void OpenAccessibilityPrivacySettings() {
  NSString* url = @"x-apple.systempreferences:com.apple.preference.security?Privacy_Accessibility";
  [[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:url]];
}
