#include <nan.h>
#include "addon.h"

void IsTrustedAccessibilityClientMethod(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  if (info.Length() < 1 || !info[0]->IsBoolean()) {
    Nan::ThrowTypeError("Invalid arguments");
    return;
  }

  const bool prompt = info[0]->BooleanValue(Nan::GetCurrentContext()).ToChecked();
  const bool result = IsTrustedAccessibilityClient(prompt);
  info.GetReturnValue().Set(Nan::New(result));
}

void OpenAccessibilityPrivacySettingsMethod(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  OpenAccessibilityPrivacySettings();
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("isTrustedAccessibilityClient").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(IsTrustedAccessibilityClientMethod)->GetFunction());
  exports->Set(Nan::New("openAccessibilityPrivacySettings").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(OpenAccessibilityPrivacySettingsMethod)->GetFunction());
}

NODE_MODULE(addon, Init)
