

{
    
    'target_defaults': {
        'default_configuration': 'Release',
        'msvs_settings': {
            'VCCLCompilerTool': {
                'ExceptionHandling': 1,
            },
        },
        'conditions': [
            ['OS == "win"', {
                'defines': ['WIN32'],
            }],
        ],
        'configurations': {
            'Debug': {
                'defines!': [
                    'NDEBUG',
                ],
               'defines': [
                    'DEBUG',
                ],       
                'cflags': [
                    '-O0',
                ],
                'xcode_settings': {
                    'MACOSX_DEPLOYMENT_TARGET': '10.7',
                    'GCC_OPTIMIZATION_LEVEL': '0',
                    'GCC_GENERATE_DEBUGGING_SYMBOLS': 'YES',
                },
                'msvs_settings': {
                    'VCLinkerTool': {
                        'GenerateDebugInformation': 'true',
                    },
                },
            },
            'Release': {
                'defines!': [
                   'DEBUG',
                   '_DEBUG',
                ],
                'defines': [
                    'NDEBUG',
                ],
                'cflags': [
                    '-O3',
                ],
                'xcode_settings': {
                    'MACOSX_DEPLOYMENT_TARGET': '10.7',
                    'GCC_OPTIMIZATION_LEVEL': '3',
                    'GCC_GENERATE_DEBUGGING_SYMBOLS': 'NO',
                    'DEAD_CODE_STRIPPING': 'YES',
                    'GCC_INLINES_ARE_PRIVATE_EXTERN': 'YES',
                },
            },
        },
    },

}