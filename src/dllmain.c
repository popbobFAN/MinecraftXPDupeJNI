#include <windows.h>
#include <stdio.h>
#include <jni.h>

void dupe() {
    AllocConsole();
    freopen("CONOUT$", "w", stdout);

    puts("kys!?!?!");

    JavaVM* jvmp;
    GetProcAddress(GetModuleHandleA("jvm.dll"), "JNI_GetCreatedJavaVMs")(&jvmp, 1, NULL);
    JavaVM jvm = *jvmp;

    JNIEnv* envp;
    jvm->AttachCurrentThread(jvmp, &envp, NULL);
    JNIEnv env = *envp;
   
    jclass minecraft = env->FindClass(envp, "bsu"); //Minecraft class
    jfieldID theMinecraftFieldID = env->GetStaticFieldID(envp, minecraft, "P", "Lbsu;");
    jobject mc = env->GetStaticObjectField(envp, minecraft, theMinecraftFieldID); //theMinecraft (THE MINECRAFT)
    
    jfieldID playerFieldID = env->GetFieldID(envp, minecraft, "h", "Lcio;");
    jobject player = env->GetObjectField(envp, mc, playerFieldID); //thePlayer (THE PLAYER)

    env->CallObjectMethod(envp, player, env->GetMethodID(envp, env->GetObjectClass(envp, player), "a", "(I)V"), 10000); //duping some exp levels for the player (sign nbt reference)

    jvm->DetachCurrentThread(jvmp);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        dupe();
    }
}